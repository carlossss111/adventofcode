package day.eight;

public class Main {
    public static void main(String[] args) {
        Forest forest = new Forest();
        System.out.println("Answer 1 = " + forest.countVisibleFromOutside());
        System.out.println("Answer 2 = " + forest.findMostScenic());
    }
}