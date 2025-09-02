module.exports = async (req, res) => {
  if (req.method !== 'POST') {
    return res.status(405).send('Méthode non autorisée');
  }

  let body = '';
  req.on('data', chunk => {
    body += chunk.toString();
  });

  req.on('end', () => {
    try {
      const data = JSON.parse(body);
      console.log("État reçu :", data);
      res.status(200).json({ message: "État reçu avec succès", data });
    } catch (err) {
      res.status(400).json({ error: "JSON invalide" });
    }
  });
};
