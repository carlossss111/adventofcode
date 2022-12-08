package day.eight;

import java.util.ArrayList;
import java.util.List;

/* A 2d array full of trees */
public class Forest {
    ReaderWrapper reader;
    List<List<Tree>> forest = new ArrayList<>();

    public Forest() {
        reader = new ReaderWrapper("src/main/resources/puzzle_input.txt");
        String line;

        //create trees
        int i = 0;
        while((line = reader.readLine()) != null) {
            forest.add(new ArrayList<>());
            for (char c : line.toCharArray()) {
                forest.get(i).add(new Tree(c));
            }
            i++;
        }

        //set their adjacency
        for(i = 1; i < forest.size() -1; i++){
            for(int j = 1; j < forest.get(0).size() -1; j++) {
                Tree tree = forest.get(i).get(j);
                tree.setAdjacency(
                        forest.get(i).get(j-1),
                        forest.get(i+1).get(j),
                        forest.get(i).get(j+1),
                        forest.get(i-1).get(j)
                );
            }
        }
    }

    //PART ONE
    public int countVisibleFromOutside() {
        int count = 0;
        for(int i = 0; i < forest.size(); i++){
            for(int j = 0; j < forest.get(0).size(); j++) {
                Tree tree = forest.get(i).get(j);
                if(tree.isVisible()) {
                    count++;
                }
            }
        }
        return count;
    }

    //PART TWO
    public int findMostScenic() {
        int max = 0;
        for(int i = 0; i < forest.size(); i++){
            for(int j = 0; j < forest.get(0).size(); j++) {
                Tree tree = forest.get(i).get(j);
                if(tree.sceneryScore() > max){
                    max = tree.sceneryScore();
                }
            }
        }
        return max;
    }
}
