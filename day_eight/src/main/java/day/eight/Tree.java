package day.eight;

/* A tree that knows it's neighbours */
public class Tree {
    Tree north = null;
    Tree east = null;
    Tree south = null;
    Tree west = null;

    int height;

    public Tree(char c) {
        height = Character.getNumericValue(c);
    }

    public int getHeight(){
        return height;
    }

    public void setAdjacency(Tree north, Tree east, Tree south, Tree west) {
        this.north = north;
        this.east = east;
        this.south = south;
        this.west = west;
    }

    //PART ONE - whether or not trees are visible from the edges
    private boolean isVisibleFromNorth (int startingHeight) {
        if (north == null){
            return true;
        } else if(startingHeight > north.getHeight()){
            return north.isVisibleFromNorth(startingHeight);
        }
        return false;
    }

    private boolean isVisibleFromEast (int startingHeight) {
        if (east == null){
            return true;
        } else if(startingHeight > east.getHeight()){
            return east.isVisibleFromEast(startingHeight);
        }
        return false;
    }

    private boolean isVisibleFromSouth (int startingHeight) {
        if (south == null){
            return true;
        } else if(startingHeight > south.getHeight()){
            return south.isVisibleFromSouth(startingHeight);
        }
        return false;
    }

    private boolean isVisibleFromWest(int startingHeight) {
        if (west == null){
            return true;
        } else if(startingHeight > west.getHeight()){
            return west.isVisibleFromWest(startingHeight);
        }
        return false;
    }

    public boolean isVisible() {
        return isVisibleFromNorth(this.height) || isVisibleFromEast(this.height)
                || isVisibleFromSouth(this.height) || isVisibleFromWest(this.height);
    }

    //PART TWO - trees visible from starting point
    private int sceneryFromNorth(int startingHeight) {
        if (north == null){
            return 0;
        } else if(startingHeight > north.getHeight()){
            return north.sceneryFromNorth(startingHeight) + 1;
        }
        return 1;
    }

    private int sceneryFromEast(int startingHeight) {
        if (east == null){
            return 0;
        } else if(startingHeight > east.getHeight()){
            return east.sceneryFromEast(startingHeight) + 1;
        }
        return 1;
    }

    private int sceneryFromSouth(int startingHeight) {
        if (south == null){
            return 0;
        } else if(startingHeight > south.getHeight()){
            return south.sceneryFromSouth(startingHeight) + 1;
        }
        return 1;
    }

    private int sceneryFromWest(int startingHeight) {
        if (west == null){
            return 0;
        } else if(startingHeight > west.getHeight()){
            return west.sceneryFromWest(startingHeight) + 1;
        }
        return 1;
    }

    public int sceneryScore() {
        return sceneryFromNorth(this.height) * sceneryFromEast(this.height)
                * sceneryFromSouth(this.height) * sceneryFromWest(this.height);
    }

}
