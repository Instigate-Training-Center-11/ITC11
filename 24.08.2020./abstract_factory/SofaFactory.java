package abstract_factory;

public class SofaFactory implements FurnitureFactory {
    @Override
    public Victorian createVictorian() {
        return new VictorianSofa();
    }

    @Override
    public Modern createModern() {
        return new ModernSofa();
    }
}
