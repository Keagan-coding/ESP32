function ToggleLED(action) {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/" + action, true);
    xhr.send();
  }

  function UpdateLEDState() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("ledState").innerHTML = this.responseText;
      }
    };
    xhr.open("GET", "/state", true);
    xhr.send();
  }

  setInterval(UpdateLEDState, 500); // Refresh LED state every second
  // function CreateColorDropDown() {}

  async function fetchJsonData() {
    try {
        // Make an asynchronous GET request to the /getData endpoint
        const response = await fetch('/Dropdowndata');

        // Parse the JSON data
        const jsonData = await response.json();
        const dropdown = document.getElementById("ColorDropdown");

        // Clear any existing options in the dropdown
        dropdown.innerHTML = '';

        // Populate the dropdown with options
        for (const [key, value] of Object.entries(jsonData)) {
            const option = document.createElement("option");
            option.value = value; // Use the value from JSON as the value for the option
            option.textContent = key; // Use the key from JSON as the display text
            dropdown.appendChild(option);
        }
        function GetColorSelection()
        {
          color = document.getElementById("ColorDropdown").value;
          console.log(color);
        }
        dropdown.onchange= GetColorSelection;
    } catch (error) {
        console.error('Error fetching JSON data:', error);
    }
}

// Call the function to fetch data when the page loads
fetchJsonData();
function GetColorSelection()
{
  color = document.getElementById("ColorDropdown").value;
  var xhr = new XMLHttpRequest();
  // xhr.onreadystatechange = function() {
  //   if (this.readyState == 4 && this.status == 200) {
  //    color
  //   }
  // };
  xhr.open("GET", "/color?selectedColor=" + encodeURIComponent(color), true);
  xhr.send();
  console.log(color);
}