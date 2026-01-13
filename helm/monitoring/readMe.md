# Notes

- Prometheus is a time series database which keeps track of all the metrics of the pods and nodes in the cluster

- Grafana is a tool used for visualing all the data collected by prometheus

# Steps to deploy the kube prometheus monitoring stack using helm

- helm repo add prometheus-community https://prometheus-community.github.io/helm-charts 

- helm repo update

- helm search repo prometheus-community 

- helm install prometheus-stack prometheus-community/kube-prometheus-stack --namespace monitoring --create-namespace

# Adding values.yaml file for the helm chart

- helm show values prometheus-community/kube-prometheus-stack > default-values.yaml

# Updating values.yaml

- Updated default admin password for grafana in the new values.yaml file

- helm upgrade prometheus-stack prometheus-community/kube-prometheus-stack -n monitoring --values=values.yaml
