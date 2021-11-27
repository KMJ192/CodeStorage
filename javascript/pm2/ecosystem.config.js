module.exports = {
  apps: [
    {
      name: "app",
      script: "javascript/pm2/app.js",
      instance: 10,
      exec_mode: "cluster",
      wait_ready: true,
      listen_timeout: 10000,
      kill_timeout: 5000,
    },
  ],
};
