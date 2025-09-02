let relay1 = false;
let relay2 = false;

module.exports = (req, res) => {
  const { relay } = req.query;
  if (relay === '1') relay1 = !relay1;
  if (relay === '2') relay2 = !relay2;
  res.json({ relay1, relay2 });
};
