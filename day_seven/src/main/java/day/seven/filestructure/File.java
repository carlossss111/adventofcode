package day.seven.filestructure;

import java.util.List;

/* Taking inspiration from the UNIX file system, everything is a File */
public interface File {
    String getName();
    long getSize();
    File getParent();
    List<File> getChildren();
    void addChild(File child);
}
