package Sender;

import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class SendData {

  private static final DecimalFormat decimalFormat = new DecimalFormat("0.0000");
  private static final float MAX_TEMP = 45;
  private static final float MIN_TEMP = 0;
  private static final float MAX_CURRENT = 15;
  private static final float MIN_CURRENT = -15;
  private static final int NO_OF_SENSOR_DATA = 50;

  public static void main(final String[] args) {

    List<Float> curSensorData = simulateCurrentData();
    List<Float> tempSensorData = simulateTempData();
    printSensorDataToConsole(curSensorData, tempSensorData);
  }


  public static int printSensorDataToConsole(final List<Float> curSensorData, final List<Float> tempSensorData) {
    int error = 0;
    try {
      for (int i = 0; i < NO_OF_SENSOR_DATA; i++) {
        streamToConsole(constructDataInCsv(curSensorData, tempSensorData, i));
      }
    }
    catch (Exception e) {
      error = 1;
    }
    return error;
  }

  public static void streamToConsole(final String data) throws IOException {
    System.out.println(data);
  }


  public static String constructDataInCsv(final List<Float> curSensorData, final List<Float> tempSensorData,
      final int i) {
    return curSensorData.get(i) + " , " + tempSensorData.get(i);
  }

  public static List<Float> simulateCurrentData() {
    return simulateData(MIN_CURRENT, MAX_CURRENT);
  }

  public static List<Float> simulateTempData() {
    return simulateData(MIN_TEMP, MAX_TEMP);
  }

  public static List<Float> simulateData(final float min, final float max) {
    List<Float> sensorData = new ArrayList<>();
    for (int i = 0; i < NO_OF_SENSOR_DATA; i++) {
      sensorData.add(preprocessData(simulateSingleData(min, max)));
    }
    return sensorData;
  }

  public static Float preprocessData(final Float data) {
    return Float.parseFloat(decimalFormat.format(data));
  }


  public static Float simulateSingleData(final float min, final float max) {
    return (float) (Math.random() * (max - min)) + min;
  }
}
