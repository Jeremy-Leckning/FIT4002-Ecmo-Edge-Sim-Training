import React, { useRef, useEffect } from "react";
import axios from "axios";

const Chart = (props) => {
  const { data, id } = props;
  const chartRef = useRef(undefined);

  useEffect(() => {
    /* NEED TO ALLOW CORS ON SERVER SIDE TO ACCESS API */
    // axios
    //   .get(
    //     "https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/vitals/1/0.02"
    //   )
    //   .then(function (response) {
    //     // handle success
    //     console.log(response);
    //   })
    //   .catch(function (error) {
    //     // handle error
    //     console.log(error);
    //   })
    //   .then(function () {
    //     // always executed
    //   });

    // Create chart, series and any other static components.
    console.log("create chart");
    const lcjs = require("@arction/lcjs");

    // Extract required parts from LightningChartJS.
    const { lightningChart, AxisScrollStrategies, Themes, emptyLine } = lcjs;

    // Create a XY Chart.
    let chart = lightningChart()
      .ChartXY({
        container: id,
        height: 420,
        width: 650,
        // theme: Themes.darkGold
      })
      .setTitle("ECG");

    // Create line series optimized for regular progressive X data.
    const series = chart
      .addLineSeries({
        dataPattern: {
          // pattern: 'ProgressiveX' => Each consecutive data point has increased X coordinate.
          pattern: "ProgressiveX",
          // regularProgressiveStep: true => The X step between each consecutive data point is regular (for example, always `1.0`).
          regularProgressiveStep: true,
        },
      })
      // Destroy automatically outscrolled data (old data becoming out of scrolling axis range).
      // Actual data cleaning can happen at any convenient time (not necessarily immediately when data goes out of range).
      .setMaxPointCount(10000)
      .setMouseInteractions(false);

    // Setup view nicely.
    chart
      .getDefaultAxisY()
      .setInterval(-1, 1)
      .setStrokeStyle(emptyLine)
      .setScrollStrategy(AxisScrollStrategies.expansion);

    chart
      .getDefaultAxisX()
      .setStrokeStyle(emptyLine)
      .setScrollStrategy(AxisScrollStrategies.progressive);

    // Store references to chart components.
    chartRef.current = { chart, series };

    // Return function that will destroy the chart when component is unmounted.
    return () => {
      // Destroy chart.
      console.log("destroy chart");
      chart.dispose();
      chartRef.current = undefined;
    };
  }, [id]);

  useEffect(() => {
    const components = chartRef.current;
    if (!components) return;

    // Set chart data.
    // Import data-generators from 'xydata'-library.
    const { createSampledDataGenerator } = require("@arction/xydata");

    // Points that are used to generate a continuous stream of data.

    const sample_point = [
      0, 0, 0, 0, 0, 0, 0, 0, -0.039, -0.004, 0.068, 0.0015, -0.05, -0.0715,
      -0.081, -0.0745, 0.175, 0.668, -0.077, -0.038, -0.035, -0.033, -0.018,
      -0.007, 0.01, 0.0325, 0.063, 0.0955, 0.145, 0.183, 0.201, 0.209, 0.139,
      0.05, -0.018, -0.037, -0.037, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    ];

    let point = [];
    let temp = { x: 0, y: 0 };
    for (let i = 0; i < sample_point.length; i++) {
      temp = { x: i, y: sample_point[i] };
      point.push(temp);
    }

    // Create a data generator to supply a continuous stream of data.
    createSampledDataGenerator(point, 50, 10)
      .setSamplingFrequency(50)
      .setInputData(point)
      .generate()
      .setStreamBatchSize(2)
      .setStreamInterval(25)
      .setStreamRepeat(true)
      .toStream()
      .forEach((point) => {
        // Push the created points to the series.
        series.add({ x: point.timestamp, y: point.data.y });
      });

    const { series } = components;
  }, [data, chartRef]);
  return <div id={id} className="chart"></div>;
};

export default Chart;
