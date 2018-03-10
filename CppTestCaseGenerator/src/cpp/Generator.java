package cpp;

import cpp.domain.AirPlane;
import cpp.domain.AirPlaneFactory;
import cpp.domain.Command;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zuce wei on 2018/3/9.
 */
public class Generator {
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

    public void generator(){
        int commandNum=0;
        List<String> commandStrList=new ArrayList<String>();
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
        }

        List<AirPlane> list=new ArrayList<AirPlane>(airPlaneList.size());
        //开始调度,正常调度
        for(int i=0;i<num;i++){
            int random=randomInt(airPlaneList.size(),0);
            AirPlane plane=randomPlane(random);
            time=time+randomInt(3,0);

            String com=Command.command_join+" "+plane.getId()+" "+time;
            commandStrList.add(com);
            commandNum++;

            commandList.add(new Command(Command.command_join,plane.getId(),time));

            list.add(plane);
            time++;
            if(randomInt(2,0)==0){
                //增加更大的随机性
                time--;
            }
        }
        generatorINputFile(commandStrList,"schedule");
//        Scheduler_backup scheduler=new Scheduler_backup();
        Scheduler scheduler =new Scheduler();
        scheduler.schedule(list,commandList);
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

    void generatorINputFile(List<String> list,String type){
        System.out.println(list.size()+1);
        for(String s:list){
            System.out.println(s);
        }
        System.out.println(type);
        System.out.println("-----------------------end input------------------");
    }

    public static void main(String a[]){
        Generator generator=new Generator();
        generator.generator();


    }
}
