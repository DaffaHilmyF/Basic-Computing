package Game;

public class NPC extends Character implements Playable {
    protected int xp;
    protected boolean isRage;

    public NPC(String name, int hp, int ap, int attack, int accuracy, int xp) {
        super(name, hp, ap, attack, accuracy);
        this.xp = xp;
        isRage = false;
    }

    @Override
    public int attackBase() {
        if(random.nextInt(101) < accuracy)
            return attack;
        return 0;
    }

    @Override
    public int Death() {
        if(hp <= 0){
            isDead = true;
            isRage = false;
            return xp;
        }
        return 0;
    }

    @Override
    public int Skill(int param, int accuracy) {
        if(random.nextInt(101) < accuracy)
            return attack * param;
        return 0;
    }

    @Override
    public void Defend() {
        ap++;
    }

    @Override
    public void changeTurn() {
        setTurn();
    }

    @Override
    public void deletingHP(int del) {
        deletingAP(del);
        if(this.hp < 30 && !isRage){
            isRage = true;
            attack *= 2;
        }
        if(this.hp <= 0){
            isDead = true;
        }
    }

    public int AIBehaviour(){
        int key = random.nextInt(101);
        if(key > 85){
            return Skill(2,75);
        }else if(key < 30){
            Defend();
            return 0;
        }else {
            return attackBase();
        }
    }
}