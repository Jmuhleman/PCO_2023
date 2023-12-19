# TESTS sur ce labo à documenter

- 2 clients 0 sièges d'attente.
  contrôle sans file d'attente possible → OK les clients attendent dehors
- 1 client 3 sièges d'attente
  contrôle sans file d'attente nécessaire → OK le client se dirige directement 
  vers le barbier
- 2 clients 3 sièges d'attente
  gestion normale et synchonisation entre les clients → OK. l'ordre de 
  traitement est respecté
- 10 clients 9 sièges d'attente
  gestion normale et synchonisation entre les clients → OK.  l'ordre de
  traitement est respecté.
- Chaque scénario a été testé avec une terminaison correcte des threads.

- AJOUTER ENCORE SI BESOIN
