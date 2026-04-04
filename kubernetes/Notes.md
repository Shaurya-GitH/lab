# Practical Notes

- Always make use of -h or --help flag to retrieve information from the CLI only. Most information will be present there.
    
   `kubectl get -h | less` 

- Use the --dry-run=client -o yaml flags to generate resource manifests.

    `kubectl create service clusterip nginx-svc --dry-run=client -o yaml --tcp=80:80 > nginx-svc.yaml`

- Use exec command to get into terminal of a container (Useful for diagnosis)

    `kubectl exec podName -it -- bash`

- Setting a default namespace

    `kubectl config set-context --current --namespace=my-ns`

- Port forwarding is useful for direct, temporary access to a pod or service without exposing it through kubernetes networking. The request gets routed through the control plane instead of the data plane

    `kubectl port-forward podName 9000`

- Use the watch command to monitor resources.

    `watch -n 1 "kubectl get pods"`

- Always look in the kubernetes documentation if the information you need if not available through -h or explain

- To update the values of a configmap or secret, you can get YAML from kubectl create and pipe it to kubectl apply

    `kubectl create configmap foo --from-file=/foo.properties --dry-run=client -o yaml | kubectl apply -f -`

- Use the `describe` command to get essential resource information

    kubectl describe svc/my-ns
