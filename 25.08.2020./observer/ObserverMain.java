package observer;

public class ObserverMain {
    public static void main(String[] args) {
        JavaDeveloperJobs jobs = new JavaDeveloperJobs();

        jobs.addVacancy("Java junior developer");
        jobs.addVacancy("Java middle developer");

        Observer numberOne = new Subscriber("John Smith");
        Observer numberTwo = new Subscriber("Nikole Kidman");

        jobs.addObserver(numberOne);
        jobs.addObserver(numberTwo);

        jobs.addVacancy("Java senior developer");
    }
}
