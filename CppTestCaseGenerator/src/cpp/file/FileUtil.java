package cpp.file;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileUtil {

    public static void writeByFileOutputStream(String path,String fileName,List<String> contents) {
        File pathFile = new File(path);
        if(!pathFile.exists()){
            pathFile.mkdirs();
        }
        File file=new File(path+"/"+fileName);
        FileWriter fw = null;
        BufferedWriter writer = null;
        try {
            fw = new FileWriter(file);
            writer = new BufferedWriter(fw);
            String line;
            for(int i=0;i<contents.size();i++){
                line=contents.get(i);
                writer.write(line);
                if(i!=(contents.size()-1)){
                    writer.newLine();//换行 ,但保证最后一行不换行
                }

            }
            writer.flush();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }catch (IOException e) {
            e.printStackTrace();
        }finally{
            try {
                writer.close();
                fw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String args[]){
        List<String> contents=new ArrayList<>();
        contents.add("this");
        contents.add("is 111");
        contents.add("a");
        contents.add("demo");
        String path="/Users/wzce17/test1/";
        FileUtil.writeByFileOutputStream(path,"test_demo.txt",contents);

    }
}
