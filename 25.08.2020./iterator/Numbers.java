package iterator;

public class Numbers implements GetterItarator {
        public Integer numbers[] = {2,4,6,8};

        @Override
        public Iterator getIterator() {
            return new NumberIterator();
        }

        private class NumberIterator implements Iterator {
            int index;

            @Override
            public boolean hasNext() {
                if(index < numbers.length){
                    return true;
                }
                return false;
            }

            @Override
            public Object next() {
                if(this.hasNext()){
                    return numbers[index++];
                }
                return null;
            }
        }
    }
