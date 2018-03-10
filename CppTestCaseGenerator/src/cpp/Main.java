package cpp;

import cpp.domain.*;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zuce wei on 2018/3/8.
 */
public class Main {
    public static List<AirPlane> airPlaneList=new ArrayList<AirPlane>();
    public static void main(String args[]){
        List list=new ArrayList<AirPlane>();
        AirPlane battle=new BattlePlane();
        battle.setId("p1");
        battle.setTakeOffTime(2);
        battle.setTaskTime(2);
        battle.setLandTime(2);
        list.add(battle);

        AirPlane transport=new TransportPlan();
        transport.setId("p2");
        transport.setTakeOffTime(3);
        transport.setTaskTime(1);
        transport.setLandTime(3);
        list.add(transport);

        AirPlane he=new HelicopterPlan();
        he.setId("p3");
        he.setTakeOffTime(1);
        he.setTaskTime(4);
        he.setLandTime(1);
        list.add(he);

        AirPlane hee=new HelicopterPlan();
        hee.setId("p4");
        hee.setTakeOffTime(1);
        hee.setTaskTime(6);
        hee.setLandTime(1);
        list.add(hee);

//        String [][]comm={
//                {join p1 0}
//                join p3 0
//                join p2 1
//                landfirst 7 p2
//                schedule
//        };

        List commandList=new ArrayList<Command>();
        commandList.add(new Command("join","p1",0));
        commandList.add(new Command("join","p3",0));
        commandList.add(new Command("join","p2",1));
        commandList.add(new Command("join","p4",1));
        commandList.add(new Command("landfirst","p2",7));
        commandList.add(new Command("schedule",null,0));

        Scheduler_backup scheduler=new Scheduler_backup();
        scheduler.schedule(list,commandList);

    }

    static List<AirPlane> input(){
        List list=new ArrayList<AirPlane>();

        return list;
    }
}
