package day.seven.filestructure;

import java.util.List;

public class DataFile implements File {
    private final File parent;
    private final String name;
    private final long size;

    public DataFile(String name, File parent, long size) {
        this.parent = parent;
        this.name = name;
        this.size = size;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public long getSize() {
        return size;
    }

    @Override
    public File getParent() {
        return parent;
    }

    @Override
    public void addChild(File child) {
        //do nothing
    }

    @Override
    public List<File> getChildren() {
        return null;
    }
}
