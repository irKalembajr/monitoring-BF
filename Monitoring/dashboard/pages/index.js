import { useEffect, useState } from "react";

export default function Home() {
  const [state, setState] = useState({ relay1: false, relay2: false, switch: false });

  useEffect(() => {
    const interval = setInterval(async () => {
      const res = await fetch("/api/update");
      const data = await res.json();
      setState(data);
    }, 1000);
    return () => clearInterval(interval);
  }, []);

  return (
    <div style={{ fontFamily: "Arial", padding: "2rem" }}>
      <h1>ESP32 Dashboard</h1>
      <p>Relay 1: {state.relay1 ? "ON" : "OFF"}</p>
      <p>Relay 2: {state.relay2 ? "ON" : "OFF"}</p>
      <p>Local Switch: {state.switch ? "ON" : "OFF"}</p>
    </div>
  );
}