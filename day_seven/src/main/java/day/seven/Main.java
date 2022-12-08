package day.seven;

public class Main {
    public static void main(String[] args) {
        Terminal terminal = new Terminal("src/main/resources/puzzle_input.txt");

        while(terminal.runCommand());

        terminal.goToRoot();
        System.out.println("Answer 1 = " + terminal.calc
                .getSumOfDirectoriesWithSizesAtMostN(100000));

        terminal.goToRoot();
        System.out.println("Answer 2 = " + terminal.calc
                .getSmallestDirectoryThatWouldFreeEnoughSpace(70000000, 30000000));
    }
}