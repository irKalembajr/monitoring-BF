let currentState = { relay1: false, relay2: false, switch: false };

export default function handler(req, res) {
  if (req.method === "POST") {
    const { relay1, relay2, localSwitch } = req.body;
    currentState = { relay1, relay2, switch: localSwitch };
    return res.status(200).json({ success: true });
  }
  res.status(200).json(currentState);
}