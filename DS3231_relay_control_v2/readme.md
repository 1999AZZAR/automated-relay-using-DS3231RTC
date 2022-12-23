<h1>RTC Auto On-Off</h1>

<p>This program uses a Real Time Clock (RTC) module to control a relay. The RTC is set to a specific time, and the relay is turned on or off based on that time. The time can be modified by changing the <code>hours</code> and <code>minutes</code> variables in the <code>auto_onoff()</code> function.</p>

<h2>Dependencies</h2>

<p>This program requires the following libraries:</p>

<ul>
  <li><a href="http://github.com/JChristensen/DS3232RTC">DS3232RTC</a></li>
  <li><a href="https://www.arduino.cc/en/Reference/Wire">Wire</a></li>
</ul>

<h2>Setup</h2>

<ol>
  <li>Install the required libraries.</li>
  <li>Connect the RTC module to your Arduino according to the instructions in the DS3232RTC library.</li>
  <li>Connect the relay to the Arduino on digital pin 4.</li>
  <li>Uncomment the lines in the <code>setup()</code> function to set the time on the RTC. After setting the time, remember to comment these lines out.</li>
  <li>Modify the <code>hours</code> and <code>minutes</code> variables in the <code>auto_onoff()</code> function to the desired on and off times for the relay. The time is in 24-hour format.</li>
  <li>Upload the program to your Arduino.</li>
</ol>

<h2>Usage</h2>

<p>The program will continuously check the current time from the RTC and turn the relay on or off based on the <code>hours</code> and <code>minutes</code> variables in the <code>auto_onoff()</code> function. The current time and date are also printed to the serial monitor for reference.</p>
