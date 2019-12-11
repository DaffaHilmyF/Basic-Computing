package Game;

public class Player extends Character implements Playable {
    private int level;
    private int xp;
    private int score;

    public Player(String name, int hp, int ap, int attack) {
        super(name, hp, ap, attack);
        level = 1;
        xp = 0;
        score = 0;
    }

    @Override
    public int attackBase() {
        if(random.nextInt(101) < accuracy)
            return attack;
        return 0;
    }

    @Override
    public int Death() {
        // do somethigs
        return score;
    }

    public void addScore(int score){
        this.score += score;
    }

    @Override
    public int Skill(int param, int accuracy) {
        if(random.nextInt(101) < accuracy)
            return attack * param;
        return 0;
    }

    @Override
    public void Defend() {
        setAp(1);
    }

    @Override
    public void changeTurn() {
        setTurn();
    }

    @Override
    public void deletingHP(int del) {
        deletingAP(del);
        if(hp <= 0)
            isDead = true;
    }

    public void getXP(int xp){
        this.xp += xp;
        if(this.xp >= 100){
            levelUp(5,5);
            this.xp -= 100;
        }
    }

    public void levelUp(int attack, int ap){
        level++;
        this.attack += attack;
        this.ap += ap;
    }
}
