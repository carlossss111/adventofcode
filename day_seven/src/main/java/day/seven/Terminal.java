package day.seven;

import day.seven.filestructure.DataFile;
import day.seven.filestructure.Directory;
import day.seven.filestructure.File;

import java.util.Arrays;

/* Reads the commands line by line and executes them */
public class Terminal {
    public Calculator calc = new Calculator();
    private final ReaderWrapper reader;
    private final File rootDirectory;
    private File currentDirectory;

    public Terminal(String filePath) {
        reader = new ReaderWrapper(filePath);
        rootDirectory = new Directory("/", null);
        currentDirectory = rootDirectory;
    }

    //Changes the current working directory to parent or child or root
    private void changeDir(String newDir) {
        if (newDir.equals("/")){
            currentDirectory = rootDirectory;
        } else if (newDir.equals("..")) {
            currentDirectory = currentDirectory.getParent();
            return;
        }

        for (File child: currentDirectory.getChildren()){
            if(child.getName().equals(newDir)){
                currentDirectory = child;
                break;
            }
        }
    }

    public void goToRoot() {
        changeDir("/");
    }

    //In this exercise, listing the Directories actually creates their contents
    //The files listed after running this command are the files to be created
    private void listDir() {
        String line;
        line = reader.readLine();
        while(line != null && line.charAt(0) != '$') {
            reader.mark();

            String[] splitLine = line.split(" ");
            if (splitLine[0].equals("dir")) {
                currentDirectory.addChild(
                        new Directory(splitLine[1], currentDirectory)
                );
            } else {
                currentDirectory.addChild(
                        new DataFile(splitLine[1], currentDirectory, Long.parseLong(splitLine[0]))
                );
            }

            line = reader.readLine();
        }
        reader.reset(); //go back one line so "$" can be re-read
    }

    //Runs the next command from the file; returns false when at the end.
    public boolean runCommand() {
        String fullStr = reader.readLine();
        if(fullStr == null){
            return false;
        }
        String[] str = fullStr.split(" ");

        System.out.println(Arrays.toString(str));
        if(str[1].equals("cd")) {
            changeDir(str[2]);
        } else if(str[1].equals("ls")) {
            listDir();
        } else {
            throw new RuntimeException("File read as command!");
        }
        return true;
    }

    /* For challenge parts one and two */
    public class Calculator {
        private static long sizeSum;
        private static long lowestSize;

        Calculator() {
            sizeSum = 0;
            lowestSize = Long.MAX_VALUE;
        }

        //PART ONE - return the sum of all directory sizes less than N
        public long getSumOfDirectoriesWithSizesAtMostN(long N) {
            for (File child : currentDirectory.getChildren()) {
                if (child.getChildren() != null) {
                    currentDirectory = child;
                    if (currentDirectory.getSize() <= N) {
                        sizeSum += currentDirectory.getSize();
                    }
                    getSumOfDirectoriesWithSizesAtMostN(N);
                }
            }
            return sizeSum; //1444896
        }

        //PART TWO - return smallest directory that would free enough space to meet the target
        private long findClosestToMin(long minTarget){
            for (File child : currentDirectory.getChildren()) {
                if (child.getChildren() != null) {
                    currentDirectory = child;
                    if (currentDirectory.getSize() > minTarget && currentDirectory.getSize() < lowestSize) {
                        lowestSize = currentDirectory.getSize();
                    }
                    findClosestToMin(minTarget);
                }
            }

            return lowestSize; //404395
        }

        public long getSmallestDirectoryThatWouldFreeEnoughSpace(long totalAvailable, long target){
            long unusedSpace = totalAvailable - rootDirectory.getSize();
            long closenessToTarget = target - unusedSpace;
            return findClosestToMin(closenessToTarget);
        }
    }

}
