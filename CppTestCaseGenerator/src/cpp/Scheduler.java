package cpp;

import cpp.domain.AirPlane;
import cpp.domain.Command;

import java.util.*;

public class Scheduler {
    int currentTaskRemainTime=0;
    AirPlane currentPlane;//当前占用跑道的飞机
    int time=0;

    Queue<AirPlane> flyList;
    Queue<AirPlane> landList;
    List<AirPlane> taskList=new ArrayList<AirPlane>();

    List<AirPlane> doneList=new ArrayList<AirPlane>();//已经完成调度的飞机

    Comparator<AirPlane> takeOffOrder =  new Comparator<AirPlane>(){
        public int compare(AirPlane p1, AirPlane p2) {
//            System.out.println("比较");
            //起飞优先级
            //加入甲板的飞机按照加入甲板的先后顺序进行起飞
            //直升机>战斗机>运输机，如果飞机类型相同则编号里数字小的先起飞
//            System.out.println("起飞比较  p1:"+p1.toString());
//            System.out.println("起飞比较  p2:"+p2.toString());
//            System.out.println("--------------------------------------------------------------");
            int res;
            if(p1.getArriveTime()<p2.getArriveTime()){
                res= 1;
            }else if(p1.getArriveTime()==p2.getArriveTime()){
                if(p1.getType().equals(p2.getType())){
                    if(p1.getId().length()==p2.getId().length()){
                        res= p1.getId().compareTo(p2.getId());
                    }else {
                        res= p1.getId().length()<p2.getId().length()?1:0;
                    }
                }else{
                   res= (p1.takeOffOrder-p2.takeOffOrder);
                }
            }else {
                res= -1;
            }
            return -res;
        }
    };

    Comparator<AirPlane> lanOrder =  new Comparator<AirPlane>(){
        public int compare(AirPlane p1, AirPlane p2) {
           // 机降落时按照返航的顺序进行降落（先返航到达甲板的飞机先降落，
            // 如果返航到达甲板的时刻相同，则降落优先级为
            // 运输机>战斗机>直升机，
            // 如果飞机类型相同则编号里数字小的先降落）。
//            System.out.println("降落比较  ");
//            System.out.println("降落比较  p1:"+p1.toString());
//            System.out.println("降落比较  p2:"+p2.toString());
//            System.out.println("--------------------------------------------------------------");
            if(p1.getLandOrder()>p2.getLandOrder()){
                return -1;
            }else if(p1.getLandOrder()<p2.landOrder){
                return 1;
            }
            //剩下的就是等级相同的情况
            if(p1.getBackTime()<p2.getBackTime()){
                return -1;
            }else if(p1.getBackTime()==p2.getBackTime()){
                if(p1.getType().equals(p2.getType())){
                    if(p1.getId().length()==p2.getId().length()){
                        return -p1.getId().compareTo(p2.getId());
                    }else {
                        return p1.getId().length()<p2.getId().length()?-1:1;
                    }
                }else{
//                    System.out.println("比较飞机的 机型*-*-*-*-*-*-*-*-*");
                    return -(p1.landOffOrder-p2.landOffOrder);
                }
            }else {
                return 1;
            }
        }
    };

    public void schedule(List<AirPlane> list, List<Command> commandList){
        System.out.println("开始调度");
        List<String> res=new ArrayList<>();
        int number=0;
//        System.out.println("开始调度");
        //优先队列使用示例
         flyList = new PriorityQueue<AirPlane>(list.size(),takeOffOrder);
         landList=new PriorityQueue<AirPlane>(list.size(),lanOrder);
        for(;;time++){

//            System.out.println("-----时刻:  "+time+"  taskList.size(): "+
//                    taskList.size()+" land: "+landList.size()+"  fly: "+flyList.size()+"  currentRemainTime: "+currentTaskRemainTime);
            for(Command command:commandList){
                if(Command.state_used.equals(command.state)){
                    continue;
                }
                //System.out.println(" Command: "+command.toString()+"  nowTime: "+time);
                if (time==command.getTime()){
                    if(Command.command_join.equals(command.getCommand())){

                        //该时刻有加入甲板的飞机，则加入就绪队列
                        AirPlane plane=find(list,command.getObject());
                        System.out.println("加入甲板--： "+plane.getId()+" time: "+time);
                        plane.setArriveTime(time);
                        showStatus(time,plane.id,command.getCommand());
                        flyList.add(plane);
                    }
                    else if(Command.command_landfirst.equals(command.getCommand())){
                        //执行优先降落的命令
                        AirPlane plane=find(list,command.getObject());
//                        landList.remove(plane);
                        AirPlane.landOrderNumber++;   //通过优先降落顺序提高降落的优先级
                        plane.setState(AirPlane.state_land);//直接进入降落状态
                        plane.setLandOrder(AirPlane.landOrderNumber);
                        landList.add(plane);

                        showStatus(time,plane.id,command.getCommand());
                    }
                    command.state=Command.state_used;
//                    commandList.remove(command);
                }
            }

            if(currentTaskRemainTime<=0 && currentPlane!=null){
                if( AirPlane.state_take_off.equals(currentPlane.getState())){
                    //该飞机刚才还在起飞状态
                    currentPlane.setState(AirPlane.state_task);//飞机进入任务状态
                   // currentPlane.setLandTimeCurrent(time);
//                    showStatus(time,currentPlane.id,"起飞结束");
                    taskList.add(currentPlane);

                }
                else if(AirPlane.state_land.equals(currentPlane.getState())){
                    //该飞机刚才还处于降落状态，现在已经降落完
                    //landList.remove(currentPlane);
                    currentPlane.setLandTimeCurrent(time);
                    number++;
                    System.out.println(number+ "  *-*-*-**-*-  time: "+time+"  "+currentPlane.display(Command.command_schedule));//飞行完则输出
                    //res.add(currentPlane.display(Command.command_schedule));
//                    showStatus(time,currentPlane.id,"降落结束");
                    doneList.add(currentPlane);
                }
                currentPlane=null;
            }

            if(currentTaskRemainTime<=0 && currentPlane==null){
                //当前没有飞机占用跑道在起飞或者降落
                if(flyList.size()!=0){
                    //就绪的等待起飞队列有飞机，则优先选择一架起飞
                    currentPlane=flyList.poll();
                    currentPlane.setState(AirPlane.state_take_off);//设置该飞机的起飞状态
                    currentPlane.setTakeOffCurrent(time);
                    currentTaskRemainTime=currentPlane.getTakeOffTime();
//                    showStatus(time,currentPlane.id,"开始起飞");
                }
                if(landList.size()!=0){
//                    showStatus(time,currentPlane.id,"开始降落");
                    currentPlane=landList.poll();
//                    System.out.println("准备队列弹出一架飞机");
//                    showStatus(time,currentPlane.id,"开始降落");
                    currentPlane.setState(AirPlane.state_land);//设置飞机的起飞状态为降落
                    currentTaskRemainTime=currentPlane.getLandTime();
                }
            }

            if(taskList.size()==0 && flyList.size()==0 && landList.size()==0 && currentTaskRemainTime<=0 && list.size()==0){
                //说明所以调度任务结束
                break;
            }
            currentTaskRemainTime--;
            List<AirPlane> tmp=new ArrayList<AirPlane>();
            for(AirPlane plane:taskList){
                if(!AirPlane.state_task.equals(plane.getState())){
                    continue;
                }
                plane.taskTime--;
                if(plane.taskTime<=0){
                    plane.setState(AirPlane.state_land);//由任务状态转为降落状态
                    plane.setBackTime(time);
                    landList.add(plane);
                    tmp.add(plane);
//                    taskList.remove(plane);
                }
            }
            for(AirPlane plane:tmp){
                taskList.remove(plane);
            }
        }//end for 调度的循环

        for(String str:res){
            System.out.println(str);
        }
    }

    void showStatus(int time,String id,String action){
        //System.out.println("时刻： "+time+ " id: "+id+" "+action);
    }

     AirPlane find(List<AirPlane> list, String id){
        AirPlane plane=null;
        int loc=-1;
        for(int i=0;i<list.size();i++){
            if(id.equals(list.get(i).getId())){
                plane=list.get(i);
                loc=i;
            }
        }
        if(loc!=-1){
            list.remove(loc);
        }
        return plane;
    }
}
