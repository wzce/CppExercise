package cpp.domain;

/**
 * Created by zuce wei on 2018/3/8.
 */
public class AirPlane implements Cloneable{

    public static final String state_normal="normal";
    public static final String state_take_off="take_off";
    public static final String state_task="task";
    public static final String state_land="land";

    public static final String type_battle="battleplane";
    public static final String type_transport="transportplane";
    public static final String type_helicopter="helicopter";

    public static int landOrderNumber=0;
    public int takeOffTime;
    public int taskTime;
    public int landTime;
    public int arriveTime;//到达甲板的时间
    public int backTime; //返航的时间

    public String id;
    public String type;
    public String state;

    public int takeOffCurrent;
    public int landTimeCurrent;
    public int landOrder;

    public int takeOffOrder;//飞机的起飞顺序，用于同一时刻不同机型的比较

    public int landOffOrder;// 飞机的降落优先级，用于同一时刻不同机型的比较

    public AirPlane(){}


    public AirPlane(int takeOffTime,int taskTime,int landTime){
        this.takeOffTime=takeOffTime;
        this.taskTime=taskTime;
        this.landTime=landTime;
    }

    public int getTakeOffTime() {
        return takeOffTime;
    }

    public void setTakeOffTime(int takeOffTime) {
        this.takeOffTime = takeOffTime;
    }


    public int getTaskTime() {
        return taskTime;
    }

    public void setTaskTime(int taskTime) {
        this.taskTime = taskTime;
    }

    public int getLandTime() {
        return landTime;
    }

    public void setLandTime(int landTime) {
        this.landTime = landTime;
    }

    public int getArriveTime() {
        return arriveTime;
    }

    public void setArriveTime(int arriveTime) {
        this.arriveTime = arriveTime;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public int getTakeOffCurrent() {
        return takeOffCurrent;
    }

    public void setTakeOffCurrent(int takeOffCurrent) {
        this.takeOffCurrent = takeOffCurrent;
    }

    public int getLandTimeCurrent() {
        return landTimeCurrent;
    }

    public void setLandTimeCurrent(int landTimeCurrent) {
        this.landTimeCurrent = landTimeCurrent;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getBackTime() {
        return backTime;
    }

    public void setBackTime(int backTime) {
        this.backTime = backTime;
    }

    public int getLandOrder() {
        return landOrder;
    }

    public void setLandOrder(int landOrder) {
        this.landOrder = landOrder;
    }

    public String display(String type){
        if(Command.command_normal.equals(type)){
            return (id+" "+takeOffTime+" "+taskTime+" "+ landTime);
        }else {
            return (id+" "+takeOffCurrent+" "+landTimeCurrent);
        }
    }

    @Override
    public String toString() {
        return "AirPlane{" +
                "takeOffTime=" + takeOffTime +
                ", taskTime=" + taskTime +
                ", landTime=" + landTime +
                ", arriveTime=" + arriveTime +
                ", backTime=" + backTime +
                ", id='" + id + '\'' +
                ", type='" + type + '\'' +
                ", state='" + state + '\'' +
                ", takeOffCurrent=" + takeOffCurrent +
                ", landTimeCurrent=" + landTimeCurrent +
                ", landOrder=" + landOrder +
                ", takeOffOrder=" + takeOffOrder +
                ", landOffOrder=" + landOffOrder +
                '}';
    }

//    public AirPlane copy(){
//        AirPlane airPlane=new AirPlane();
//        airPlane.id=this.id;
//        airPlane.taskTime=taskTime;
//        airPlane.arriveTime=arriveTime;
//        airPlane.landTime=landTime;
//        airPlane.takeOffTime=takeOffTime;
//        airPlane.backTime=backTime;
//        airPlane.landOrder=landOrder;
//        airPlane.takeOffCurrent=takeOffCurrent;
//        airPlane.landTimeCurrent=landTimeCurrent;
//        airPlane.landOffOrder=landOffOrder;
//
//        return airPlane;
//    }

    @Override
    public Object clone() {
        AirPlane stu = null;
        try{
            stu = (AirPlane) super.clone();
        }catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return stu;
    }
}
