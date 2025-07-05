const box = document.getElementById("box");
const toggleText = document.getElementById("toggle-text");
const statusText = document.getElementById("status-text");

let isOn = false;

box.addEventListener("click", () => {
    isOn = !isOn;

    // Shrink animation
    box.classList.add("shrink");
    setTimeout(() => {
        box.classList.remove("shrink");
    }, 200);

    // Update UI
    const status = isOn ? "ON" : "OFF";
    toggleText.textContent = status;
    statusText.textContent = `Button is ${status}`;
    statusText.style.color = isOn ? "green" : "red";

    // Show temporary loading message
    statusText.textContent += " (Sending...)";

    // Send POST request to AWS API Gateway
    fetch("https://03s5cwwel1.execute-api.eu-north-1.amazonaws.com/prod/led", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({ status: status })
    })
    .then(response => response.json())
    .then(data => {
        console.log("Lambda Response:", data);
        statusText.textContent = `LED is ${status} ✔`;
    })
    .catch(error => {
        console.error("Error calling API:", error);
        statusText.textContent = `Failed to update LED ❌`;
        statusText.style.color = "orange";
    });
});
