package cpp.domain;

/**
 * Created by zuce wei on 2018/3/8.
 */
public class TransportPlan extends AirPlane {
       public TransportPlan(){
           this.takeOffTime=3;
           this.taskTime=0;
           this.landTime=3;
           this.type= AirPlane.type_transport;

           //起飞：直升机>战斗机>运输机
           //降落：运输机>战斗机>直升机
           this.takeOffOrder=1;
           this.landOffOrder=3;
       }
}
