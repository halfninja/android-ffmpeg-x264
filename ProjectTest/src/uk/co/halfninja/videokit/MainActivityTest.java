package uk.co.halfninja.videokit;

import android.test.InstrumentationTestCase;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class uk.co.halfninja.videokit.MainActivityTest \
 * uk.co.halfninja.videokit.tests/android.test.InstrumentationTestRunner
 */
public class MainActivityTest extends InstrumentationTestCase {

    public MainActivityTest() {
//        super("uk.co.halfninja.videokit", MainActivity.class);
    }

    public void testVideokit() {
        Videokit vk = new Videokit();
        vk.run(new String[]{
            "ffmpeg", "-version"
        });
        assertNotNull(vk);
    }

}
