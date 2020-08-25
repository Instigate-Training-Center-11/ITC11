package observer;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        User user1 = new User("Status1", "User1", new ArrayList<>(), new ArrayList<>());
        User user2 = new User("Status2", "User2", new ArrayList<>(), new ArrayList<>());
        User user3 = new User("Status3", "User3", new ArrayList<>(), new ArrayList<>());

        user1.addFollower(user2);
        user1.addFollower(user3);

        user1.setStatus("new status1!");
        user1.setStatus("new status2!");

        System.out.println(user2.getEmail());
        System.out.println(user3.getEmail());
    }
}
