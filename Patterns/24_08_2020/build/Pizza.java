package build;

public class Pizza {
    private String size;
    private String cheese;
    private String sauce;
    private String ham;
    private String mushrooms;

    public void setSize(String size) {
        this.size = size;
    }

    public void setCheese(String cheese) {
        this.cheese = cheese;
    }

    public void setSauce(String sauce) {
        this.sauce = sauce;
    }

    public void setHam(String ham) {
        this.ham = ham;
    }

    public void setMushrooms(String mushrooms) {
        this.mushrooms = mushrooms;
    }

    @Override
    public String toString() {
        return "Pizza{" +
                "size='" + size + '\'' +
                ", cheese='" + cheese + '\'' +
                ", sauce='" + sauce + '\'' +
                ", ham='" + ham + '\'' +
                ", mushrooms='" + mushrooms + '\'' +
                '}';
    }
}