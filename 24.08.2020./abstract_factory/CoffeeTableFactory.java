package abstract_factory;

public class CoffeeTableFactory implements FurnitureFactory{
    @Override
    public Victorian createVictorian() {
        return new VictorianTable();
    }

    @Override
    public Modern createModern() {
        return new ModernTable();
    }
}
