package observer;

import java.util.List;

public class User {
    private String status;
    private String name;
    private List<String> email;
    private List<User> followers;

    public User() {
        this.email = null;
        this.followers = null;
        this.name = null;
        this.status = null;
    }

    public User(String status, String name, List<String> email, List<User> followers) {
        this.status = status;
        this.name = name;
        this.email = email;
        this.followers = followers;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String newStatus) {
        for(User user: followers) {
            user.addEmail(this.name + " change his/her status. New status is: " + newStatus);
        }
        this.status = newStatus;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<String> getEmail() {
        return email;
    }

    public void setEmail(List<String> email) {
        this.email = email;
    }

    public void addEmail(String email) {
        this.email.add(email);
    }

    public List<User> getFollowers() {
        return followers;
    }

    public void setFollowers(List<User> followers) {
        this.followers = followers;
    }

    public void addFollower(User follower) {
        this.followers.add(follower);
    }
}
