package cpp.domain;

/**
 * Created by zuce wei on 2018/3/8.
 */
public class BattlePlane extends AirPlane {
    public BattlePlane(){
        this.takeOffTime=2;
        this.taskTime=0;
        this.landTime=2;
        this.type= AirPlane.type_battle;
        //起飞：直升机>战斗机>运输机
        //降落：运输机>战斗机>直升机
        this.takeOffOrder=2;
        this.landOffOrder=2;
    }
}
