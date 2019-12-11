package Game;

import DataBase.Score;
import java.io.*;

public class GameManager {
    private int level;
    private static GameManager manager = null;
    private Player player;
    private NPC enemy;
    private Score score;

    private GameManager(){
        player = null;
        score = new Score();
        IntialDatabase();
    }

    public static GameManager getInstance(){
        if(manager == null)
            manager = new GameManager();
        return manager;
    }
    
    public Player getPlayer(){
        return player;
    }
    
    public NPC getEnemy(){
        return enemy;
    }
    
    public void setPlayer(Player player){
        if(this.player == null){
            level = 1;
            this.player = player;
        }
    }
    
    public void setEnemy(NPC npc){
        this.enemy = npc;
    }

    public Score getScore() {
        return score;
    }
    
    
    
    // <editor-fold defaultstate="collapsed" desc=" Physhics ">
    public int getLevel() {
        return level;
    }

    public boolean canNextLevel(){
        if(enemy.isDead()){
            level++;
            player.getXP(enemy.xp);
            enemy = null;
            return true;
        }
        return false;
    }
    
    public int Attack(){
        int attk = player.attackBase();
        return attk;
    }
    
    public int SkillAttack(int param, int acc){
        int attk = player.Skill(param, acc);
        return attk;
    }
    
    public void Defend(){
        player.Defend();
    }
    
    public boolean isGameOver(){
        if(player.isDead()){
            player = null;
            return true;
        }
        return false;
    }
    
    public void ColiderNPC(int attack){
        enemy.deletingHP(attack);
        enemy.changeTurn();
    }

    public void ColiderPlayer(int attack){
        player.deletingHP(attack);
        player.changeTurn();
    }
    
    public String AIEnemy(){
        String condition = "";
        int tmp = enemy.ap;
        int attack = enemy.AIBehaviour();
        if(enemy.ap != tmp){
            condition = "Enemy Defend +1 AP";
        }else if(attack == 0){
            condition = "Enemy Miss Attack";
        }else if(attack == enemy.attack){
            condition = "Enemy Basic Attack";
        }else{
            condition = "Enemy Skill Attack";
        }
        ColiderPlayer(attack);
        return condition;
    }
    // </editor-fold>
    
    // <editor-fold defaultstate="collapsed" desc=" Database ">
    public void IntialDatabase(){
        try{
            score.ReadFile();
        }catch(FileNotFoundException e){
            System.out.println("File Tidak Ada");
        }
    }
    
    public void SaveData(int level, String nama){
        try{
            score.addScore(level, nama);
            score.SaveFile();
        }catch(IOException e){
            // do Nothing
        }
    }
    
    public String getData(int i){
        return score.getScore(i);
    }
    
    // </editor-fold>
}