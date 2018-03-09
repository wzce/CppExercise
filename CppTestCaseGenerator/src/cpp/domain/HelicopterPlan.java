package cpp.domain;

/**
 * Created by zuce wei on 2018/3/8.
 */
public class HelicopterPlan extends AirPlane {
    public HelicopterPlan(){
        this.takeOffTime=1;
        this.taskTime=0;
        this.landTime=1;
        this.type= AirPlane.type_helicopter;

        //起飞：直升机>战斗机>运输机
        //降落：运输机>战斗机>直升机
        this.takeOffOrder=3;
        this.landOffOrder=1;
    }
}
