/**
 * Created by ZhongRui on 2015/07/31.
 */

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexTest {

    public static void main(String argv[]) {

        String line = "This order was placed for QT3000! OK?";
        String pattern = "(\\d+)(.*)";

        Pattern r = Pattern.compile(pattern);
        Matcher m = r.matcher(line);
        if (m.find()) {
            System.out.println(m.group(0));
            System.out.println(m.group(1));
            System.out.println(m.group(2));
        }
    }
}
