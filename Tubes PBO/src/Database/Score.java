package DataBase;

import java.io.*;
import java.util.*;

public class Score {
    
    class HighScore{
        int level;
        String nama;
        public HighScore(int level, String nama){
            this.level = level;
            this.nama = nama;
        }

        @Override
        public String toString() {
            return Integer.toString(level)+ " " + nama + '\n';
        }
        
    }
    private ArrayList<HighScore> highScore;
    private File file;
    
    public Score(){
        highScore = new ArrayList<HighScore>();
        file = new File("src\\Database\\Hall_of_Fame.txt");
    }
    
    public void addScore(int level, String nama){
        highScore.add(new HighScore(level, nama));
    }
    
    public String getScore(int i){
        return highScore.get(i).toString();
    }
    
    public int getSize(){
        return highScore.size();
    }
    
    class SortByLevel implements Comparator<HighScore>{
        public int compare(HighScore a, HighScore b){
            return b.level - a.level;
        }
    }
    
    public void sortList(){
        Collections.sort(highScore,new SortByLevel());
        if(highScore.size() > 5){
            highScore.remove(5);
        }
    }
    
    public void ReadFile() throws FileNotFoundException{ 
        Scanner sc = new Scanner(file);
        while(sc.hasNextLine()){
            int level = sc.nextInt();
            String name = sc.nextLine();
            addScore(level, name);
        }
    }
    
    public void SaveFile() throws IOException{
        BufferedWriter writer = new BufferedWriter(new FileWriter(file));
        sortList();
        for(HighScore x : highScore){
            writer.write(x.toString());
        }
        writer.close();
    }
    
    public String getNM(int i){
        return highScore.get(i).nama;
    }
    
    public int getLVL(int i){
        return highScore.get(i).level;
    }
}