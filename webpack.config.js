const path = require('path');

module.exports = {
  entry: './examples/index.bs.js',
  output: {
    path: path.join(__dirname, "build"),
    filename: 'index.js',
  },
};
