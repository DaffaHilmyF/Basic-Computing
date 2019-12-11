package Game;

public interface Playable {
    public int Skill(int param,int accuracy);
    public void Defend();
    public void changeTurn();
    public void deletingHP(int del);
}
