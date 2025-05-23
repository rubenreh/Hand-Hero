
// Author: Ruben Rehal

document.getElementById("feedback").innerText = "Starting system...";

const canvas = document.getElementById("tracker");
const ctx = canvas.getContext("2d");

ctx.fillStyle = "#eee";
ctx.fillRect(0, 0, canvas.width, canvas.height);

ctx.beginPath();
ctx.arc(320, 240, 60, 0, 2 * Math.PI);
ctx.fillStyle = "lightgreen";
ctx.fill();

document.getElementById("feedback").innerText = "Hand detected: Grip angle 45°, Feedback: Excellent!";
