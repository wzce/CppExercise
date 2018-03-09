package cpp.domain;

/**
 * Created by zuce wei on 2018/3/8.
 */
public class Command {
    public static final String command_join="join";
    public static final String command_set="set";
    public static final String command_landfirst ="landfirst";
    public static final String command_add="add";
    public static final String command_normal="normal";
    public static final String command_schedule="schedule";

    public static final String state_not_used="not_used";
    public static final String state_used="used";



    public String state="not_used";

    String command; //具体的命令
    int time; //命令发生的时间
    String object;  //命令的对象

    public Command(String command,String object,int time){
        this.command=command;
        this.object=object;
        this.time=time;
    }

    public String getCommand() {
        return command;
    }

    public void setCommand(String command) {
        this.command = command;
    }

    public int getTime() {
        return time;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public String getObject() {
        return object;
    }

    public void setObject(String object) {
        this.object = object;
    }

    @Override
    public String toString() {
        return "Command{" +
                "state='" + state + '\'' +
                ", command='" + command + '\'' +
                ", time=" + time +
                ", object='" + object + '\'' +
                '}';
    }
}
