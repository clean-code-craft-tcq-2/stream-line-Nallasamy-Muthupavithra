package Sender;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.List;

import Sender.Sender;
import org.junit.Test;

public class SenderTest {

  @Test
  public void testSimulateSingleData() {
    Float data = Sender.simulateSingleData(1, 5);
    testRange(data, 1, 5);
  }

  private void testRange(final Float data, final float min, final float max) {
    assertTrue(data <= max);
    assertTrue((data >= min));
  }

  @Test
  public void testPreprocessData() {
    Float data = Sender.preprocessData((float) 5.6789004);
    assertTrue(Float.compare((float) 5.6789, data) == 0);
  }

  @Test
  public void testConstructDataInCsv() {
    List<Float> curSensorData = new ArrayList<>();
    List<Float> tempSensorData = new ArrayList<>();
    curSensorData.add((float) -14.2346);
    tempSensorData.add((float) 34.6788);
    String data = Sender.constructDataInCsv(curSensorData, tempSensorData, 0);
    System.out.println(data);
    assertTrue(data.equals("-14.2346 , 34.6788"));
  }

  @Test
  public void testSendData() {
    List<Float> curSensorData = Sender.simulateCurrentData();
    assertEquals(50, curSensorData.size());
    List<Float> tempSensorData = Sender.simulateTempData();
    assertEquals(50, tempSensorData.size());
    int error = Sender.printSensorDataToConsole(curSensorData, tempSensorData);
    assertEquals(error, 0);
  }
}
