package day.eight;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/* Wraps the reader so that I do not have to deal with exceptions */
public class ReaderWrapper {
    private BufferedReader reader;

    public ReaderWrapper(String filePath) {
        try {
            reader = new BufferedReader(new FileReader(filePath));
        } catch (FileNotFoundException e) {
            System.out.println("Could not read input file!");
            System.exit(1);
        }
    }

    public String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            System.out.println("Could not read line by line!");
            System.exit(2);
        }
        return "";
    }

    public void mark() {
        try {
            reader.mark(1000);
        } catch (IOException e) {
            System.out.println("Could not run reader.mark()!");
            System.exit(3);
        }
    }

    public void reset() {
        try {
            reader.reset();
        } catch (IOException e) {
            System.out.println("Could not run reader.reset()!");
            System.exit(4);
        }
    }
}
