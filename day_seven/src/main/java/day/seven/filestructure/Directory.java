package day.seven.filestructure;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicLong;

public class Directory implements File {
    private final File parent;
    private final String name;
    private final List<File> files = new ArrayList<>();

    public Directory(String name, File parent) {
        this.parent = parent;
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }

    //returns the size of the files and other directories inside recursively
    @Override
    public long getSize() {
        AtomicLong size = new AtomicLong();
        files.forEach(file -> size.addAndGet(file.getSize()));
        return size.longValue();
    }

    @Override
    public File getParent() {
        return parent;
    }

    @Override
    public void addChild(File child) {
        files.add(child);
    }

    @Override
    public List<File> getChildren() {
        return files;
    }
}
