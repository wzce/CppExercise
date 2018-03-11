package cpp;

import cpp.domain.AirPlane;
import cpp.domain.AirPlaneFactory;
import cpp.domain.Command;
import cpp.file.FileUtil;

import java.lang.reflect.GenericDeclaration;
import java.util.*;

/**
 * Created by zuce wei on 2018/3/9.
 */
public class Generator {

    //三个进阶难度
    public static final String type_basic="basic";
    public static final String type_easy="easy";
    public static final String type_hard="hard";

    public String planeType[]={
            AirPlane.type_battle, AirPlane.type_transport, AirPlane.type_helicopter
    };

    public int time=0; //时刻

    public String command[]={
            Command.command_add,
            Command.command_join,
            Command.command_set,
            Command.command_landfirst
//            Command.command_normal,//这两个都是最后才加上去的
//            Command.command_schedule
    };

    List<AirPlane> airPlaneList;

    public void generator(String path,int testNum,String testCaseType){



        String inputName="test_"+testNum+".in";
        String outputName="test_"+testNum+".out";
        List<String> recordList=new ArrayList<>();

        int commandNum=0;
        List<String> commandStrList=new ArrayList<>();
        List<Command> commandList=new ArrayList<Command>();
        airPlaneList=new ArrayList<AirPlane>();
        int num =(int)(Math.random()*100+2);//产生飞机的数目,2--102架
        int id=0;
        for(int i=0;i<num;i++){
            //添加num架飞机
            int loc=(int)(Math.random()*3);
            //Command command=new Command(Command.command_add,"p"+i,0);
            String co="add "+planeType[loc]+" p"+i;
            commandStrList.add(co);
            commandNum++;

            AirPlane plane= AirPlaneFactory.generator(planeType[loc]);
            plane.setId("p"+i);

            airPlaneList.add(plane);
//
        }

        //设置飞机的起飞，做任务、降落的耗时
        for(AirPlane plane:airPlaneList){
            int takeOff=randomInt(20,2);
            int task=randomInt(20,2);
            int land=randomInt(20,2);
            String com="set "+plane.getId()+" "+takeOff+" "+task+" "+land;
            plane.setTakeOffTime(takeOff);
            plane.setTaskTime(task);
            plane.setLandTime(land);
            //airPlaneList.add(plane);
            commandStrList.add(com);
            commandNum++;
            recordList.add(plane.display(Command.command_normal));//basic的需求
        }


        if(Generator.type_basic.equals(testCaseType)){
            generatorInputFile(commandStrList,Command.command_normal,path,inputName);
            System.out.println(inputName);
            FileUtil.writeByFileOutputStream(path,outputName,recordList);//生成测试的输出测试用例
            return;
        }

        List<AirPlane> list=new ArrayList<AirPlane>(airPlaneList.size());
        //开始调度,正常调度
        for(int i=0;i<num;i++){
            int random=randomInt(airPlaneList.size(),0);
            AirPlane plane=randomPlane(random);
            time=time+randomInt(3,0);

            if(Command.command_schedule.equals(testCaseType)){
//                String com=Command.command_join+" "+plane.getId()+" "+time;
//                commandStrList.add(com);
//                commandNum++;
//                commandList.add(new Command(Command.command_join,plane.getId(),time));
            }else {
                String com=Command.command_join+" "+plane.getId()+" "+time;
                commandStrList.add(com);
                commandNum++;
                commandList.add(new Command(Command.command_join,plane.getId(),time));
            }


            list.add(plane);
            time++;
            if(randomInt(2,0)==0){
                //增加更大的随机性
                time--;
            }
        }
        generatorInputFile(commandStrList,Command.command_schedule,path,inputName);

//        Scheduler_backup scheduler=new Scheduler_backup();
        Scheduler scheduler =new Scheduler();
        List<String> outputList=scheduler.schedule(list,commandList);
        FileUtil.writeByFileOutputStream(path,outputName,outputList);//生成测试的输出测试用例
    }

    int randomInt(int up,int down){
        int num =(int)(Math.random()*(up-down)+down);
        return num;
    }

    AirPlane randomPlane(int loc){
      AirPlane plane=airPlaneList.get(loc);
      airPlaneList.remove(plane);
      return plane;
    }

    void generatorInputFile(List<String> commandList,String type,String filePath,String fileName){
//        System.out.println(commandList.size()+1);
        commandList.add(0,""+(commandList.size()+1));
        for(String s:commandList){
            //System.out.println(s);
        }
        commandList.add(type);
        FileUtil.writeByFileOutputStream(filePath,fileName,commandList);//生成测试用例的输入

        //System.out.println(type);
        System.out.println("-----------------------end input------------------");
    }

    public static void main(String a[]){
        Map<String ,Integer> typeNum=new HashMap<>();
        typeNum.put(Generator.type_basic,2);
        typeNum.put(Generator.type_easy,6);
        typeNum.put(Generator.type_hard,2);
//        String filePath=
        Generator generator=new Generator();
//        generator.generator();

    }



    void generetor(String basePath){
        Map<String ,Integer> typeNum=new HashMap<>();
        typeNum.put(Generator.type_basic,2);
        typeNum.put(Generator.type_easy,6);
        typeNum.put(Generator.type_hard,2);

        int num=1;
        String path=basePath+"/test_cases";
        for(String key : typeNum.keySet()){
            for(int i=0;i<typeNum.get(key);i++){
                time=0;
                this.generator(path,num,key);
                num++;
            }
        }
    }
}
