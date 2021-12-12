const { merge } = require("webpack-merge");
const common = require("./webpack.config.js");

const config = {
  devtool: "hidden-source-map",
  mode: "production",
  optimization: {
    runtimeChunk: {
      name: "runtime",
    },
    splitChunks: {
      cacheGroups: {
        commons: {
          test: /[\\/]node_modules[\\/]/,
          name: "vendors",
          chunks: "all",
        },
      },
    },
  },
};
