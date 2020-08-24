package abstract_factory;

public class ChairFactory implements FurnitureFactory {
    @Override
    public Victorian createVictorian() {
        return new VictorianChair();
    }

    @Override
    public Modern createModern() {
        return new ModernChair();
    }
}
