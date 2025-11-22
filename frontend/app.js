
async function sendRequest() {

    const data = {
        patientId: document.getElementById("patientId").value,
        location: document.getElementById("location").value,
        destination: document.getElementById("location2").value,
        urgency: document.getElementById("urgency").value
    };

    console.log("Sending data to backend:", data);

    await fetch("http://localhost:5000/request-ambulance", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(data)
    })
    .then(res => res.json())
    .then(result => {
        console.log("Backend Response:", result);
        alert("Ambulance request sent! Check terminal for output.");
    })
    .catch(err => console.error(err));
}
