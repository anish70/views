package swiftstack;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import junit.framework.TestCase;

import org.junit.Test;

public class TestMounts extends TestCase {

    private void assertIn(String output, String mount, int freeSpace,
            String... drives) {
        Pattern p = Pattern.compile("^([/\\w]+)");
        for (String line : output.split("\n")) {
            Matcher m = p.matcher(line);
            if (!m.find()) {
                continue;
            }
            String foundMount = m.group(1);
            if (!foundMount.equals(mount)) {
                continue;
            }
            for (String drive : drives) {
                if (!line.contains(drive)) {
                    throw new AssertionError(String.format(
                        "Did not find %s in the output corresponding"
                                + " to expected mount point %s", drive, mount));
                }
            }
            if (!line.contains(String.valueOf(freeSpace))) {
                throw new AssertionError(String.format(
                    "Did not find expected freespace amount %d for mount %s",
                    freeSpace, mount));
            }
            return;
        }
        throw new AssertionError(String.format(
            "Did not find output for mount %s", mount));
    }

    @Test
    public void testOne() {
        String mounts = "/ 500\n/var 100\n/var/lib 300";
        String reqs = "/var/lib/carson 200\n/var/foo 50\n/usr/share 1000";
        String out = new MountCalculator(mounts, reqs).calculateMounts();
        assertIn(out, "/", -500, "/usr/share");
        assertIn(out, "/var", 50, "/var/foo");
        assertIn(out, "/var/lib", 100, "/var/lib/carson");
    }

    @Test
    public void testTwo() {
        String mounts = "/ 10000\n/var 10000";
        String reqs = "/ 5000\n/var/lib 50000\n/usr 100\n/tmp 10000";
        String out = new MountCalculator(mounts, reqs).calculateMounts();
        assertIn(out, "/", 10000 - 5000 - 10000 - 100, "/usr", "/", "/tmp");
        assertIn(out, "/var", 10000 - 50000, "/var/lib");

    }
}
