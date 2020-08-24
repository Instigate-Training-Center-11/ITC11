package builder;

public class Pizza {

    private int size;
    private int mashroom;
    private int cheese;
    private int sauce;
    private int pepperoni;
    private int ham;
    private int olives;

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getMashroom() {
        return mashroom;
    }

    public void setMashroom(int mashroom) {
        this.mashroom = mashroom;
    }

    public int getOlives() {
        return olives;
    }

    public void setOlives(int olives) {
        this.olives = olives;
    }

    public int getHam() {
        return ham;
    }
    public void setHam(int ham) {
        this.ham = ham;
    }
    public void setPepperoni(int pepperoni) {
        this.pepperoni = pepperoni;
    }
    public int getPepperoni() {
        return pepperoni;
    }

    public void setSauce(int sauce) {
        this.sauce = sauce;
    }
    public int getSauce() {
        return sauce;
    }

    public void setCheese(int cheese) {
        this.cheese = cheese;
    }
    public int getCheese() {
        return cheese;
    }
}

