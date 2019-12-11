package Game;

import java.util.Random;

public abstract class Character {
    private String name;
    protected int hp;
    protected int ap;
    protected int attack;
    protected int accuracy;
    protected Random random;

    private boolean turn = true;
    protected boolean isDead = false;

    public Character(String name, int hp, int ap, int attack) {
        this.name = name;
        this.hp = hp;
        this.ap = ap;
        this.attack = attack;
        this.accuracy = 90;
        random = new Random();
    }

    public Character(String name, int hp, int ap, int attack, int accuracy){
        this.name = name;
        this.hp = hp;
        this.ap = ap;
        this.attack = attack;
        this.accuracy = accuracy;
        random = new Random();
    }

    public String getName() {
        return name;
    }

    public int getHp() {
        return hp;
    }

    public int getAp() {
        return ap;
    }

    public boolean isTurn() {
        return turn;
    }

    public boolean isDead(){
        isDead = (hp <= 0);
        return isDead;
    }

    public void setTurn() {
        this.turn = !this.turn;
    }

    public void setAp(int addAp) {
        this.ap += addAp;
    }

    public void deletingAP(int del){
        if(ap != 0){
            ap -= del;
            if(ap < 0){
                this.hp += ap;
                ap = 0;
            }
        }else{
            this.hp -= del;
        }
    }

    public abstract int attackBase();

    public abstract int Death();
}
