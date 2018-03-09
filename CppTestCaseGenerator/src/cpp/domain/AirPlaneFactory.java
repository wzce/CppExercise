package cpp.domain;

/**
 * Created by zuce wei on 2018/3/9.
 */
public class AirPlaneFactory {
    public static AirPlane generator(String type){
        if(AirPlane.type_battle.equals(type)){
            return new BattlePlane();
        }else if(AirPlane.type_helicopter.equals(type)){
            return new HelicopterPlan();
        }else {
            return new TransportPlan();
        }
    }
}
