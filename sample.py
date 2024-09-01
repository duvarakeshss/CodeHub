import googlemaps
import tkinter as tk
from tkinter import messagebox

# Initialize Google Maps API
gmaps = googlemaps.Client(key="AIzaSyAyHmK4lf7nriSYK_WzZvhNb0IJdUcohwg")  # Replace with your Google Maps API key

# Function to calculate eco-friendly route and find EV charging stations if necessary
def get_route_with_ev_support(origin, destination, vehicle_range_km, current_battery_percent):
    remaining_range_km = vehicle_range_km * (current_battery_percent / 100)
    
    # Get directions between origin and destination
    directions_result = gmaps.directions(origin, destination)
    
    if not directions_result:
        return None, "No route found between the given locations."
    
    # Calculate route distance in kilometers
    route_distance = directions_result[0]['legs'][0]['distance']['value'] / 1000
    
    # Check if charging is required
    if route_distance > remaining_range_km:
        # Calculate the midpoint of the route and search for EV charging stations
        midpoint_location = directions_result[0]['legs'][0]['end_location']
        charging_stations = get_nearest_ev_charging_stations(midpoint_location)
        return route_distance, charging_stations
    else:
        return route_distance, None

# Function to get EV charging stations near a specific location
def get_nearest_ev_charging_stations(location, radius=10000):
    places_result = gmaps.places_nearby(location=location, radius=radius, keyword="EV charging station")
    return places_result['results']


def calculate_route():
    origin = entry_origin.get()
    destination = entry_destination.get()
    vehicle_range = int(entry_range.get())
    current_battery = int(entry_battery.get())
    
    # Get the eco-friendly route
    route_distance, charging_stations = get_route_with_ev_support(origin, destination, vehicle_range, current_battery)
    
    if charging_stations:
        station_names = [station['name'] for station in charging_stations]
        messagebox.showinfo("Charging Required", f"Distance: {route_distance} km\nCharging stations nearby: {', '.join(station_names)}")
    else:
        messagebox.showinfo("Route Info", f"Distance: {route_distance} km\nNo charging stations needed!")

# Create the main window
root = tk.Tk()
root.title("Eco-Friendly Route Planner for EVs")

# Create labels and entries for user input
label_origin = tk.Label(root, text="Origin:")
label_origin.grid(row=0, column=0, padx=10, pady=10)
entry_origin = tk.Entry(root)
entry_origin.grid(row=0, column=1, padx=10, pady=10)

label_destination = tk.Label(root, text="Destination:")
label_destination.grid(row=1, column=0, padx=10, pady=10)
entry_destination = tk.Entry(root)
entry_destination.grid(row=1, column=1, padx=10, pady=10)

label_range = tk.Label(root, text="Vehicle Range (km):")
label_range.grid(row=2, column=0, padx=10, pady=10)
entry_range = tk.Entry(root)
entry_range.grid(row=2, column=1, padx=10, pady=10)

label_battery = tk.Label(root, text="Battery Level (%):")
label_battery.grid(row=3, column=0, padx=10, pady=10)
entry_battery = tk.Entry(root)
entry_battery.grid(row=3, column=1, padx=10, pady=10)

# Create a button to calculate the route
button_calculate = tk.Button(root, text="Calculate Route", command=calculate_route)
button_calculate.grid(row=4, column=0, columnspan=2, padx=10, pady=10)

# Run the Tkinter event loop
root.mainloop()