let relay1 = false;
let relay2 = false;

module.exports = (req, res) => {
  res.json({ relay1, relay2 });
};
